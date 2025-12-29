typedef struct Lfo Lfo;
typedef struct LfoPatch LfoPatch;

struct Lfo {
    uint16_t (*update)(struct Lfo *lfo);
    void (*reset)(struct Lfo *lfo);
    int rate, max;

    /* for triangle */
    int value;
    int dir;
    /* for sine */
    int x, y;
};

struct LfoPatch {
    int program_no;
    uint16_t (*update)(struct Lfo *lfo);
    void (*reset)(struct Lfo *lfo);
    uint16_t max;
    int do_retrigger;
    uint8_t top1, top2;
    uint16_t rate1, rate2;
    uint8_t next_instr_opcode;
};

uint16_t lfo_triangle_update(Lfo *lfo) {
    if (lfo->dir) {
        lfo->value += lfo->rate;
        if (lfo->value > lfo->max) {
            lfo->value = lfo->max;
            lfo->dir = 0;
        }
    } else {
        lfo->value -= lfo->rate;
        if (lfo->value < 0) {
            lfo->value = 0;
            lfo->dir = 1;
        }
    }
    assert(lfo->value >= 0 && lfo->value < 0x10000);
    return lfo->value;
}

void lfo_triangle_reset(Lfo *lfo) {
    lfo->dir = 1;
    lfo->value = 0;
}

uint16_t lfo_sine_update(Lfo *lfo) {
    int16_t clamp_pos = lfo->max;
    int16_t clamp_neg = -lfo->max;
    int16_t rate = lfo->rate;

    /* Y += X * rate >> 16 */
    lfo->y += ((int32_t)lfo->x * rate) >> 16;
    if (lfo->y > clamp_pos) lfo->y = clamp_pos;
    if (lfo->y < clamp_neg) lfo->y = clamp_neg;

    /* X -= Y * rate >> 16 */
    lfo->x -= ((int32_t)lfo->y * rate) >> 16;
    if (lfo->x > clamp_pos) lfo->x = clamp_pos;
    if (lfo->x < clamp_neg) lfo->x = clamp_neg;

    /* Convert signed to unsigned */
    return (uint16_t)(lfo->x ^ 0x8000);
}

void lfo_sine_reset(Lfo *lfo) {
    lfo->x = 0;
    lfo->y = lfo->max & 0xff00;
}


#define LFO_TRI_FULL    lfo_triangle_update, lfo_triangle_reset, 0xffff
#define LFO_TRI_HALF    lfo_triangle_update, lfo_triangle_reset, 0x7fff
#define LFO_TRI_QUARTER lfo_triangle_update, lfo_triangle_reset, 0x3fff
#define LFO_SIN_FULL    lfo_sine_update, lfo_sine_reset, 0x7eff
#define LFO_SIN_HALF    lfo_sine_update, lfo_sine_reset, 0x3eff
#define LFO_SIN_QUARTER lfo_sine_update, lfo_sine_reset, 0x1eff


LfoPatch lfo_patches[] = {
    { 50, LFO_TRI_QUARTER, 1, 0x00, 0x00, 0x03, 0x03, 0xc0 },
    { 51, LFO_TRI_QUARTER, 0, 0x00, 0x00, 0x03, 0x05, 0x80 },
    { 52, LFO_TRI_QUARTER, 0, 0x00, 0x00, 0x05, 0x05, 0xc0 },
    { 53, LFO_TRI_HALF,    1, 0x00, 0x00, 0x06, 0x07, 0x80 },
    { 54, LFO_TRI_HALF,    0, 0x00, 0x00, 0x05, 0x05, 0xc0 },
    { 55, LFO_TRI_HALF,    0, 0x00, 0x00, 0x0c, 0x0c, 0x80 },
    { 56, LFO_TRI_HALF,    0, 0x00, 0x00, 0x11, 0x11, 0xc0 },
    { 57, LFO_TRI_FULL,    1, 0x00, 0x00, 0x13, 0x17, 0x80 },
    { 58, LFO_TRI_FULL,    0, 0x00, 0x00, 0x0d, 0x0e, 0xc0 },
    { 59, LFO_TRI_FULL,    0, 0x00, 0x00, 0x17, 0x11, 0x80 },
    { 60, LFO_SIN_FULL,    0, 0x01, 0x03, 0x27, 0x1b, 0x80 },
    { 61, LFO_SIN_HALF,    0, 0x02, 0x03, 0x2e, 0x3d, 0x80 },
    { 62, LFO_SIN_FULL,    0, 0x02, 0x01, 0x2d, 0x3a, 0x80 },
    { 63, LFO_SIN_FULL,    0, 0x03, 0x02, 0x40, 0x45, 0x80 },
    { 64, LFO_SIN_HALF,    0, 0x02, 0x03, 0x4f, 0x79, 0x80 },
    { 65, LFO_SIN_HALF,    0, 0x02, 0x01, 0x94, 0x7a, 0x80 },
    { 66, LFO_SIN_FULL,    0, 0x02, 0x01, 0x4f, 0x41, 0x80 },
    { 67, LFO_SIN_HALF,    0, 0x01, 0x02, 0x70, 0x8e, 0x80 },
    // Quarter-range sine LFO runs at 4* the rate
    { 68, LFO_SIN_QUARTER, 0, 0x01, 0x01, 0xea * 4, 0xd9 * 4, 0x80 },
    { 69, LFO_SIN_QUARTER, 0, 0x01, 0x01, 0xff * 4, 0xff * 4, 0x80 },
};

/* returns non-zero if effect has patch and lfo1, lfo2 and lfo_patch were populated */
int
init_lfo_for_program(int program_no, Lfo *lfo1, Lfo *lfo2, LfoPatch **lfo_patch) {
    for (int i = 0; i < ARRAY_SIZE(lfo_patches); i++) {
        LfoPatch *lp = &lfo_patches[i];

        if (lp->program_no == program_no) {
            lfo1->update = lp->update;
            lfo1->reset = lp->reset;
            lfo1->rate = lp->rate1;
            lfo1->max = lp->max;
            lfo1->reset(lfo1);

            lfo2->update = lp->update;
            lfo2->reset = lp->reset;
            lfo2->rate = lp->rate2;
            lfo2->max = lp->max;
            lfo2->reset(lfo2);

            *lfo_patch = lp;
            return 1;
        }
    }
    return 0;
}

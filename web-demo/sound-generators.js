// Sound generation functions for Midiverb web demo
const SAMPLE_RATE = 48000;
const DURATION = 2; // 2 seconds

function generateSineBlip(ctx) {
  const buffer = ctx.createBuffer(2, SAMPLE_RATE * DURATION, SAMPLE_RATE);
  const blipDuration = 0.1; // 100ms
  const freq = 440;
  const volume = 0.5;
  for (let channel = 0; channel < 2; channel++) {
    const data = buffer.getChannelData(channel);
    for (let i = 0; i < SAMPLE_RATE * blipDuration; i++) {
      data[i] = volume * Math.sin(2 * Math.PI * freq * i / SAMPLE_RATE);
    }
    // Rest is silence (already 0)
  }
  return buffer;
}

function generateSineWave(ctx) {
  const buffer = ctx.createBuffer(2, SAMPLE_RATE * DURATION, SAMPLE_RATE);
  const freq = 440;
  const volume = 0.25;
  for (let channel = 0; channel < 2; channel++) {
    const data = buffer.getChannelData(channel);
    for (let i = 0; i < buffer.length; i++) {
      data[i] = volume * Math.sin(2 * Math.PI * freq * i / SAMPLE_RATE);
    }
  }
  return buffer;
}

function generateNoiseBurst(ctx) {
  const buffer = ctx.createBuffer(2, SAMPLE_RATE * DURATION, SAMPLE_RATE);
  const burstDuration = 0.25; // 250ms
  const volume = 0.5;
  for (let channel = 0; channel < 2; channel++) {
    const data = buffer.getChannelData(channel);
    for (let i = 0; i < SAMPLE_RATE * burstDuration; i++) {
      data[i] = (Math.random() * 2 - 1) * volume;
    }
    // Rest is silence (already 0)
  }
  return buffer;
}

function generateImpulse(ctx) {
  const buffer = ctx.createBuffer(2, SAMPLE_RATE * DURATION, SAMPLE_RATE);
  const volume = 1.0;
  // Short pulse: 1ms (48 samples at 48kHz) for better audibility
  const pulseSamples = Math.floor(SAMPLE_RATE * 0.001);
  for (let channel = 0; channel < 2; channel++) {
    const data = buffer.getChannelData(channel);
    for (let i = 0; i < pulseSamples; i++) {
      data[i] = volume;
    }
    // Rest is silence (already 0)
  }
  return buffer;
}

function generateChordSweep(ctx) {
  const buffer = ctx.createBuffer(2, SAMPLE_RATE * DURATION, SAMPLE_RATE);
  // Maj7 chord: root, major third, perfect fifth, major seventh
  // Using A (220Hz) as base: A, C#, E, G#
  const baseFreq = 220;
  const ratios = [1, 5/4, 3/2, 15/8]; // Maj7 intervals
  const volume = 0.25 / ratios.length; // 25% total volume, divided by number of notes
  const chordDuration = 0.5; // 500ms sound, rest is silence
  const chordSamples = Math.floor(SAMPLE_RATE * chordDuration);

  // Filter parameters - sweep cutoff from 8000Hz down to 200Hz
  const startCutoff = 8000;
  const endCutoff = 200;

  for (let channel = 0; channel < 2; channel++) {
    const data = buffer.getChannelData(channel);
    let filterState = 0; // One-pole lowpass filter state
    // Track phase for each oscillator
    const phases = ratios.map(() => 0);

    for (let i = 0; i < chordSamples; i++) {
      const t = i / SAMPLE_RATE;

      // Generate raw chord (sum of sines at fixed frequencies)
      let sample = 0;
      for (let j = 0; j < ratios.length; j++) {
        const freq = baseFreq * ratios[j];
        phases[j] += (2 * Math.PI * freq) / SAMPLE_RATE;
        sample += Math.sin(phases[j]);
      }
      sample *= volume;

      // Sweeping lowpass filter (one-pole)
      // Cutoff sweeps down exponentially
      const cutoffRatio = Math.pow(endCutoff / startCutoff, t / chordDuration);
      const cutoff = startCutoff * cutoffRatio;
      const rc = 1.0 / (2 * Math.PI * cutoff);
      const dt = 1.0 / SAMPLE_RATE;
      const alpha = dt / (rc + dt);

      filterState = filterState + alpha * (sample - filterState);
      data[i] = filterState;
    }
    // Rest is silence (already 0)
  }
  return buffer;
}

async function getAudioBuffer(ctx, soundSource) {
  if (soundSource === 'example.wav' || soundSource.startsWith('blob:')) {
    // Handle both example.wav and custom uploaded files (blob URLs)
    const response = await fetch(soundSource === 'example.wav' ? 'example.wav' : soundSource);
    const arrayBuffer = await response.arrayBuffer();
    return await ctx.decodeAudioData(arrayBuffer);
  } else if (soundSource === 'sine_blip') {
    return generateSineBlip(ctx);
  } else if (soundSource === 'sine_wave') {
    return generateSineWave(ctx);
  } else if (soundSource === 'noise_burst') {
    return generateNoiseBurst(ctx);
  } else if (soundSource === 'impulse') {
    return generateImpulse(ctx);
  } else if (soundSource === 'chord_sweep') {
    return generateChordSweep(ctx);
  }
  throw new Error('Unknown sound source: ' + soundSource);
}

# Validation checklist

## Checked during this update

- Sketch filenames match their parent folder names.
- Documentation points to the organized sketches.
- Each sender/receiver pair uses 9600 baud and the same packet terminator.
- Telemetry is sent before the servo advances to its next measurement angle.
- No-echo results do not trigger target plotting.
- Original uploads are retained in legacy/.

## Required hardware checks

- [ ] Compile the Arduino sketch for Uno with Servo installed.
- [ ] Start every Processing sketch in Java mode.
- [ ] Verify the serial port and close Serial Monitor.
- [ ] Confirm known target distances and angles.
- [ ] Check sweep endpoints and manual/automatic switching.
- [ ] Check no-echo behavior, LED feedback, and the 50 cm alert.
- [ ] Check external servo power and shared ground.
- [ ] Record software versions and add a real photo or short video.

## Telemetry regression cases

- Valid sample: 90,25 followed by newline; expect angle 90 and distance 25.
- Zero distance: no target marker.
- Other project's terminator: do not mix protocols.
- Malformed packets: parser hardening remains future work.

Compilation and physical execution were not available in the update environment.

# POCO Click Sounds — experimental Geode 6 source

This is **source code**, NOT an installable `.geode` mod. It is prepared for GD 2.2091 / Geode 6 beta 2 / Android64, but it has **not been built or tested**. API compatibility, linker availability for audio engine, and real-time sound playback still need validation.

## Build using GitHub on your phone
1. Sign in at github.com in a browser.
2. Create a NEW repository, e.g. `poco-click-sounds`.
3. Upload all contents of this folder to the repository root **preserving** `src/`, `resources/`, and `.github/workflows/` structure. On mobile, uploading a ZIP alone does not unpack it into a repository. You may need to use a Git client or GitHub web editor to create individual files.
4. Open Actions > Build Android64 Geode Mod > Run workflow.
5. If it succeeds, open the run > Artifacts > POCO-Click-Sounds-Android64, unzip artifact, find `.geode`.
6. Copy the `.geode` file to Geode > game > geode > mods and restart GD.

If the workflow fails, inspect the build logs and fix any errors. This package isn't a guaranteed compatible ready-to-run mod. The bundled audio is original and may be changed by replacing `resources/press.wav` and `resources/release.wav`.

## Source notes
`GJBaseGameLayer::handleButton` is a game input hook, and calls to the original function are retained. The project uses cocos SimpleAudioEngine sound playback; this method may need adaptation for Geode 6 Android and may have latency. It is not a low-latency pro clicksound engine.

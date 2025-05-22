fetch('launcher.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes, {}))
  .then(results => {
    const instance = results.instance;

    console.log("LAUNCHER: WASM loaded successfully");
    console.log(instance.exports);
  })
  .catch(err => {
    console.error("LAUNCHER: WASM failed to load ❌", err);
  });


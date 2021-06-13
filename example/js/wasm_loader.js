'use strict';

module.exports = ((mod_js, mod_wasm, opts) => {

    const mod_file = require(mod_js);
    const bin_file = require(mod_wasm);

    opts = opts || {};

    opts.wasmBinary = bin_file;
    opts.print = opts.print || ((text) => console.log(text));
    opts.printErr = opts.printErr || ((text) => console.log(`error: ${text}`));
    opts.onAbort = opts.onAbort || (() => console.log('WASM aborted!!!'));

    // == don't call main()
    if (typeof opts.noInitialRun === "undefined")
        opts.noInitialRun = true;

    // == don't terminate after returning from main()
    if (typeof opts.noExitRuntime === "undefined")
        opts.noExitRuntime = true;

    return mod_file(opts);
});

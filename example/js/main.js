'use strict';

const wasm_loader = require('wasm_loader')

var mod;
wasm_loader('app_loader', 'app_module').then((instance) => {
    console.log("WASM module loaded.");
    mod = instance;
});

module.exports.loop = function () {
    if (mod !== undefined)
        mod.loop();
}

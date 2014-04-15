/**
 * Created by King Lee on 14-4-15.
 */
var handlerMgr = require("./handlerMgr");
var consts = require("../../../util/consts");
var redis = require("redis");
handlerMgr.handler(consts.MSG_TYPE.MSG_TYPE_LOGIN, function(msg, session, next) {
    var client = redis.createClient();
    client.on("error", function (err) {
        console.log("Error " + err);
    });
    client.quit();
    next(null, {code: 200, msg: 'login is ok.'});
});
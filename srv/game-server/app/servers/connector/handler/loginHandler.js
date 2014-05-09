/**
 * Created by King Lee on 14-4-15.
 */
var handlerMgr = require("./handlerMgr");
var consts = require("../../../util/consts");
var redis_pools = require("../../../nosql/redis_pools");
handlerMgr.handler(consts.MSG_TYPE.MSG_TYPE_LOGIN, function(msg, session, next) {
    redis_pools.execute("pool_1",function(client, release){
        client.hset("chess" + ":" + "king_lee","hello","hi",function (err, reply){
            console.log(JSON.stringify(reply));
            release();
        });
    });
    next(null, {code: 200, msg: 'login is ok.'});
});
<<<<<<< HEAD
/**
 * Created by King Lee on 14-4-15.
 */
var _ = require('underscore');
var handlerMgr = module.exports;

handlerMgr.container = [];

handlerMgr.handler = function( mid,cb ) {
    this.container[mid] = cb;
};

handlerMgr.trigger = function(mid,msg,session,next ) {
    if( _.isString(mid) ){
        mid = parseInt(mid);
    }
    if( this.container[mid] ){
        this.container[mid](msg,session,next);
    }
=======
/**
 * Created by King Lee on 14-4-15.
 */
var _ = require('underscore');
var handlerMgr = module.exports;

handlerMgr.container = [];

handlerMgr.handler = function( mid,cb ) {
    this.container[mid] = cb;
};

handlerMgr.trigger = function(mid,msg,session,next ) {
    if( _.isString(mid) ){
        mid = parseInt(mid);
    }
    if( this.container[mid] ){
        this.container[mid](msg,session,next);
    }
>>>>>>> 5ff5a6570fc5d0c4a7ba04dfb9ea80f6cd3d9039
};
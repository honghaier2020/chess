var handlerMgr = require('./handlerMgr');
module.exports = function(app) {
  return new Handler(app);
};

var Handler = function(app) {
  this.app = app;
};

/**
 * New client entry chat server.
 *
 * @param  {Object}   msg     request message
 * @param  {Object}   session current session object
 * @param  {Function} next    next stemp callback
 * @return {Void}
 */
Handler.prototype.entry = function(msg, session, next) {
    handlerMgr.trigger(msg.msg_id,msg,session,next);
};

/**
 * New client entry chat server.
 *
 * @param  {Object}   msg     request message
 * @param  {Object}   session current session object
 * @param  {Function} next    next stemp callback
 * @return {Void}
 */
Handler.prototype.hello = function(msg, session, next) {
    console.log('hello handler: %j', msg);
    this.app.get('channelService').broadcast('connector', 'onHey',
        {content: 'hey~'}, {}, function(err) {
            if(err) {
                console.error(err.stack);
            }
        });
    next();
};
/**
 * it 's a test code
 * @param msg
 * @param session
 * @param next
 */
Handler.prototype.hi = function(msg, session, next) {
    console.log('hi handler: %j', msg);
    //  this way will not show the msg context completely.
    console.log('test hello handler: ' +  msg);
    console.log(msg.context1 + msg.context2);
    next(null, {msg: 'hi~~ king lee'});
};

/**
 * it 's a test code
 * @param msg
 * @param session
 * @param next
 */
Handler.prototype.echo = function(msg, session, next) {
    next(null, {body: msg.body});
};

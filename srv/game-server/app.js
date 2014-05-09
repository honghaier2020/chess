var pomelo = require('pomelo');
<<<<<<< HEAD
var httpServer = require('./app/httpServer');
=======
>>>>>>> 5ff5a6570fc5d0c4a7ba04dfb9ea80f6cd3d9039
/**
 * Init app for client.
 */
var app = pomelo.createApp();
app.set('name', 'srv');

// app configuration
app.configure('production|development', 'connector', function(){
  app.set('connectorConfig',
    {
      connector : pomelo.connectors.hybridconnector,
      heartbeat : 3,
      useDict : true,
      useProtobuf : true
    });
    app.loadConfig('redis', app.getBase() + '/config/redis.json');
    console.log("config load for redis  %s", app.getBase() + '/config/redis.json');
    require('./app/nosql/redis_pools').configure(app.get('redis'));
<<<<<<< HEAD

    //  create http server
    var http = new httpServer();
    http.createHttpServer();
    app.set('httpServer',http);
=======
>>>>>>> 5ff5a6570fc5d0c4a7ba04dfb9ea80f6cd3d9039
});

// start app
app.start();

process.on('uncaughtException', function (err) {
  console.error(' Caught exception: ' + err.stack);
});

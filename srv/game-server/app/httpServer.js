var http = require( 'http' );

var connector = function() {
	this.server = null;
	this.port = 3000;
};

connector.prototype.createHttpServer = function() {
	this.server = http.createServer(function(req, res) {
		
		var client_ip = req.connection.remoteAddress;
		console.log("new client coming " + client_ip + " " + req.method + " " + req.url);
		switch(req.method){
			case 'GET':{
				break;
			}
			case 'POST':{
				parsePost(req,res,function(args){
					this.httpMessage();
				});
				break;
			}
			default:{
                res.end();
                break;
			}
		}
	});
	this.server.listen( this.port );
};

connector.prototype.parsePost = function(req,res,cb){
	var chunks = [];
    req.on('data', function(chunk) {
        chunks.push(chunk);
    });
    
    req.on('end', function() {
        var str = chunks.join('');
        endcb([req.url, qs.parse(str)]);
    });
};

connector.prototype.httpMessage = function(client_ip,url,args,cb,req,res){
	var msg = JSON.parse( args.msg );
	console.log(args);
};
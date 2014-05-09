var http = require("http");
var qs = require("querystring");

var connector = function() {
	this.server = null;
	this.port = 3000;
};

connector.prototype.createHttpServer = function() {
    var self = this;
	this.server = http.createServer(function(req, res) {
		
		var client_ip = req.connection.remoteAddress;
		console.log("new client coming " + client_ip + " " + req.method + " " + req.url);
		switch(req.method){
			case 'GET':{
				break;
			}
			case 'POST':{
                self.parsePost(req,res,function(args){
                    self.httpMessage(client_ip,req.url,args,function(){
                            res.writeHead(200, {'Content-Type': 'text/html'});
                            res.write('<h1>hi,</h1>');
                            res.end('<p>I have get data. many thanks</p>');
                        },req,res);
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
        cb([req.url, qs.parse(str)]);
    });
};

connector.prototype.httpMessage = function(client_ip,url,args,cb,req,res){
	console.log(args);
    cb();
};

module.exports = connector;
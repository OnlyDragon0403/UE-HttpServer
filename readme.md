# Unreal Engine HttpServer example
Example how to configure and run embedded HttpServer with C++.
This HttpServer can only be run in the main thread.

Don't forget to add "HTTP" and "HTTPServer" modules to Build.cs file in sources folder.

Check HttpServer with curl console program:
```
curl -v -X GET localhost:8080/get
curl -v -X POST -H "id: 0" --data-ascii "Hello world!" localhost:8080/post
curl -v -X PUT -H "id: 0" --data-ascii "Hello world!" localhost:8080/put
```

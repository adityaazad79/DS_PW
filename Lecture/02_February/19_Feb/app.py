from flask import Flask
from flask import request

app = Flask(__name__)


@app.route("/")
def hello_world():
    return "<h1>Hello, World!</h1>"
# http://127.0.0.1:5000


@app.route("/hello_world1")
def hello_world1():
    return "<h1>Hello, World!1</h1>"
# http://127.0.0.1:5000/hello_worl1


@app.route("/hello_world2")
def hello_world2():
    return "<h1>Hello, World!2</h1>"
# http://127.0.0.1:5000/hello_world2


@app.route("/test")
def test():
    return "This is my function to run app"


@app.route("/sum")
def sum():
    return "The sum of 4 and 6 is {}" .format(4+6)
# http://127.0.0.1:5000/sum

@app.route("/sum2")
def sum2():
    data = request.args.get('x')
    return "This is a data input from my url {}".format(data)
# http://127.0.0.1:5000/sum2?x=Aditya



if __name__ == "__main__":
    app.run(host="0.0.0.0")
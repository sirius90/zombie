from OSC import OSCServer,OSCClient, OSCMessage
import sys
from time import sleep
import types
sys.path.insert(0, '/usr/lib/python2.7/bridge/') # make sure python can see the tcp module

from tcp import TCPJSONClient
													 
#set up the json client and the osc client and server. The server should have the ip of your Yun. 
#The client.connect should have the ip address of you phone. 
json = TCPJSONClient('127.0.0.1', 5700)
server = OSCServer( ("192.168.240.1", 8000) )
#client = OSCClient()
#client.connect( ("192.168.240.140", 9000) )

#waits for slider change
def handle_timeout(self):
	print ("Timeout")

server.handle_timeout = types.MethodType(handle_timeout, server)

# function to do the work. path refers to the fader name, args refers to the value of the slider
def button0_callback(path, tags, args, source):
	global fader1Feedback
	if path=="/button/A3":
		fader1Feedback = float(args[0])
		#msg = OSCMessage("/1/label1")
		#msg.insert(0, fader1Feedback)
		print "%i" % fader1Feedback
		json.send({'command':'put', 'key':'D10', 'value':'%i' % (fader1Feedback)})
		#client.send(msg)

def button1_callback(path, tags, args, source):
	global fader1Feedback
	if path=="/button/E3":
		fader1Feedback = float(args[0])
		print "%i" % fader1Feedback
		json.send({'command':'put', 'key':'D11', 'value':'%i' % (fader1Feedback)})

def button2_callback(path, tags, args, source):
	global fader1Feedback
	if path=="/button/A2":
		fader1Feedback = float(args[0])
		print "%i" % fader1Feedback
		json.send({'command':'put', 'key':'D12', 'value':'%i' % (fader1Feedback)})

def button3_callback(path, tags, args, source):
	global fader1Feedback
	if path=="/button/E2":
		fader1Feedback = float(args[0])
		print "%i" % fader1Feedback
		json.send({'command':'put', 'key':'D13', 'value':'%i' % (fader1Feedback)})


#execute
server.addMsgHandler( "/button/A3",button0_callback)
server.addMsgHandler( "/button/E3",button1_callback)
server.addMsgHandler( "/button/A2",button2_callback)
server.addMsgHandler( "/button/E2",button3_callback)

while True:
	server.handle_request()

server.close()

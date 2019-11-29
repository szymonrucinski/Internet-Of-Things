import thingspeak
import httplib
import urllib
import time
import psutil
import os

key = "DBHP2UIVIMV4W2YT" 

def ping():
    status = 0
    address = "onet.pl"
    while True:
        response = os.system("ping -c 1 " + address)
        if response == 0:
            status = 1
        else:
            status = 0
        params = urllib.urlencode({'field2': status, 'key':key }) 
        headers = {"Content-type": "application/x-www-form-urlencoded","Accept": "text/plain"}
        conn = httplib.HTTPConnection("api.thingspeak.com:80")
        try:
            conn.request("POST", "/update", params, headers)
            response = conn.getresponse()
            print (response.status, response.reason)
            data = response.read()
            conn.close()
        except:
            print ("connection failed")
        break
                
if __name__ == "__main__":
        while True:
                ping()
 



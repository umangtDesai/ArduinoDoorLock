import serial
from twilio.rest import Client

def send_sms():
        
        account_sid = "**************************"
        auth_token = "****************************"
        client = Client(account_sid, auth_token)

        message = client.api.account.messages.create(to="************",
                                             from_="**********************",
                                             body="Someone's trying to enter your room!")



arduino = serial.Serial('COM4', 9600, timeout=.1)
while True:
    data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
    if data:
            print("Wait for the SMS!")
            send_sms()      








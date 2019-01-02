import serial
from twilio.rest import Client

def send_sms():
        
        account_sid = "ACfaaab20da8f96fe6cb94d01dadada913"
        auth_token = "5af38c68728c425ddf12b2855041a5f3"
        client = Client(account_sid, auth_token)

        message = client.api.account.messages.create(to="+16468230989",
                                             from_="(646) 679-6314",
                                             body="Someone's trying to enter your room!")



arduino = serial.Serial('COM4', 9600, timeout=.1)
while True:
    data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
    if data:
            print("Wait for the SMS!")
            send_sms()      








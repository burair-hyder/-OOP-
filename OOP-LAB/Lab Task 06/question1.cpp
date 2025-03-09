/* TASK # 01
You are required to implement a simple message handling system using object-oriented
programming in C++.
Task Breakdown:
1. Create a Message class
o It should have a private instance variable text of type string to store the message
content.
o Implement a method toString() that returns the message text.
o Provide a setter method to modify the text value.
2. Create an SMS class that inherits from Message
o It should have an additional instance variable recipientContactNo to store the
recipient’s phone number.
o Implement appropriate accessor and mutator methods.
o Override the toString() method to return a concatenated string containing the
recipient’s contact number and the message text.
3. Create an Email class that inherits from Message
o It should have additional instance variables: sender, receiver, and subject.
o Implement appropriate accessor and mutator methods.
o Override the toString() method to return a concatenated string containing sender,
receiver, subject, and the message text.
4. Implement Keyword Search Function
o Define a function:
o bool ContainsKeyword(const Message& messageObject, const string& keyword);
o This function should return true if the text of the Message object contains the
given keyword, otherwise return false.
5. Implement Message Encoding
o Define a function to encode a given message using the following scheme:
 Each character should be replaced by the next character in the alphabet
(e.g., ‘A’ → ‘B’, ‘b’ → ‘c’, ‘Z’ → ‘A’, ‘z’ → ‘a’).
 Example: If the message is "This is Java", the encoded message should be
"Uijt jt Kbwb".
6. Test the Implementation
o In the main() function, create sample objects of SMS and Email, assign values,
and test the functionalities including keyword search and encoding*/



#include <iostream>
using namespace std;

class Message{
	private :
		string text;
	
	public:
		Message(){
		}	
		Message(string textp){
			text = textp;
		}
		string toString()const {
			return text;
			
		}
	
};


class SMS : public Message {
		private :
			string recipientContactNo;
			
		public:
			SMS(string text, string number):Message(text){
				recipientContactNo = number;
			}
			
			SMS (string number): Message(){
				recipientContactNo = number;
			}
			
			void setNumber(string num){
				recipientContactNo=  num;
				
			}
			string getNumber()const {
				return 	recipientContactNo;
			}
			
			string toString()  {
				return Message::toString()+ " "+getNumber();
			}
			
};

class Email : public  Message {
		private :
			
			string sender;
			string receiver;
			string subject;
		
		public:
			
			Email(string textp,string senderp, string receiverp , string subjectp): Message(textp){
				sender = senderp;
				receiver = receiverp;
				subject = subjectp;
			}
			
			void setSender(string sp){
				sender = sp;
			}
			void setReceiver(string rp){
				receiver = rp;
			}
			void setSubject(string sp){
				subject = sp;
			}
			
			string getSender(){
				return sender;
			}
			string getReceiver(){
				return receiver;
			}
			string getSubject(){
				return subject;
			}
			
			string toString(){
				return Message::toString() + " "+ sender+" "+ subject+ " "+receiver ;
			}
					
};

bool ContainsKeyword(const Message &messageObject,const string&keyword){
	string check= messageObject.toString();
	
	if (check.find(keyword)==string::npos){
		return false;
	}
	else{
		return true;
	}
}

void Encoder(string &text){
	for (int i=0;i<text.length();i++){
		int check = text[i];
		if (check==122){
			text[i] ='a';
		}
		else if (check ==90){
			text[i] ='A';
		}
		else if (text[i]!=' '){
			text[i] = text[i]+1;
		}
	}
}



int main() {
    SMS sms1("Hello, how are you?", "1234567890");
    cout << "SMS: " << sms1.toString() << endl;

    Email email1("Meeting at 5 PM", "john.doe@example.com", "jane.smith@example.com", "Project Update");
    cout << "Email: " << email1.toString() << endl;

    string keyword = "Meeting";
    if (ContainsKeyword(email1, keyword)) {
        cout << "The keyword \"" << keyword << "\" is found in the email message." << endl;
    } else {
        cout << "The keyword \"" << keyword << "\" is NOT found in the email message." << endl;
    }

    string messageText = "Hello World Zz";
    cout << "Original Text: " << messageText << endl;
    Encoder(messageText);
    cout << "Encoded Text: " << messageText << endl;

    return 0;
}


/*PROBLEM STATEMENT:
 * Load Balancing:
 * For example, imagine you have a set of servers that handle requests for a web application. 
 * The key to load balancing is using the hash value of a client's IP address or a request ID 
to determine which server should handle the request. 
 * The hash function is typically designed so that the data is evenly distributed across the servers, 
ensuring that no single server is overloaded. 
 * Write a program of a load balancing system.
*/
#include <iostream>

using namespace std;

int main() {
    cout << "Hash-based Load Balancing Techniques" << endl;
   	
    int servers, req_id, user, req_count = 0;
    
    cout << "Enter the total number of servers: ";
    cin >> servers;
	
    int hash[servers];
    
    for (int i=0; i < servers; i++) {
        hash[i] = 0;
    }
    	
    if (servers <= 0) {
    	cout << "Number of servers must be positive. Exiting." << endl;
       	return 1;
    }
    
    cout << "\nReady to process requests.";
    while (1) {		
    	cout << "\nEnter Request ID (integer): ";
    	cin >> req_id;
        
    	int i = (req_id % servers);
        if (hash[i] == 0) {
            hash[i] = req_id;
            cout << "Request ID " << req_id << " assigned to Server [" << i << "]" << endl;
        } else if (hash[i+1] == 0) {
            hash[i+1] = req_id; // Avoids overwriting at the same location
            cout << "Request ID " << req_id << " assigned to Server [" << i+1 << "]" << endl;
        } else {
            hash[i+2] = req_id; // Avoids overwriting at the same location
            cout << "Request ID " << req_id << " assigned to Server [" << i+2 << "]" << endl;
        }
        
       	req_count++;
        
       	cout<<"Do you want to continue? (1=Yes/2=No): ";
       	cin >> user;
        
       	if (user == 2) {
       		break;
       	}
   	}
   	cout << endl << req_count << " requests have been processed successfully!" << endl;
   	
    return 0;
}

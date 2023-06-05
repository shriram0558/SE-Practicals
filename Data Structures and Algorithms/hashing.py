
class data:

    def __init__(self, client_id, telephone):
        self.client_id = client_id
        self.telephone = telephone

    def __init__(self):
        self.client_id = None
        self.telephone = None

class hashMap:

    def __init__(self, n):
        self.n = n
        self.table = []
        for i in range(n):
            self.table.append(data())

    def insert(self, client_id, telephone):
        index = client_id % self.n
        for i in range(self.n):
            if(self.table[index].client_id == None):
                break
            index = (index + 1) % self.n
        self.table[index] = data(client_id, telephone)

    def search(self, client_id):
        index = client_id % self.n
        for i in range(self.n):
            if(self.table[index].client_id == client_id):
                return self.table[index].telephone
            index = (index + 1) % self.n
        return None
    
    def delete(self, client_id):
        index = client_id % self.n
        for i in range(self.n):
            if(self.table[index].client_id == client_id):
                self.table[index] = data()
                return
            index = (index + 1) % self.n


if __name__ == '__main__':

    choice = -1
    database = hashMap(10)
    
    while True:
        print("************* MENU *************")
        print("1. Insert Client Details")
        print("2. Search Client Details")
        print("3. Delete Client Details")
        print("4. Exit")
        print("Enter your choice:", end=" ")
        choice = int(input())

        if(choice == 1):
            print("Enter Client ID:", end=" ")
            client_id = int(input())
            print("Enter Telephone Number:", end=" ")
            telephone = int(input())
            database.insert(client_id, telephone)
        elif(choice == 2):
            print("Enter Client ID:", end=" ")
            client_id = int(input())
            telephone = database.search(client_id)
            if(telephone == None):
                print("Client ID not found")
            else:
                print("Telephone Number:", telephone)
        elif(choice == 3):
            print("Enter Client ID:", end=" ")
            client_id = int(input())
            database.delete(client_id)
        elif(choice == 4):
            break
        else:
            print("Invalid choice")

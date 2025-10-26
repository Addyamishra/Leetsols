class Bank {
public:
    vector<long long> balance;

    Bank(vector<long long>& balance) {
        this->balance = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        int a = account1 - 1;
        int b = account2 - 1;
        if (a < 0 || a >= balance.size() || b < 0 || b >= balance.size()) 
            return false;
        if (balance[a] < money) 
            return false;
        balance[a] -= money;
        balance[b] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        int a = account - 1;
        if (a < 0 || a >= balance.size()) 
            return false;
        balance[a] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        int a = account - 1;
        if (a < 0 || a >= balance.size() || balance[a] < money) 
            return false;
        balance[a] -= money;
        return true;
    }
};

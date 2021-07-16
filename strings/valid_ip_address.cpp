
  #include<bits/stdc++.h>
   using namespace std ;

bool valid(string s) {
    return !s.empty() && s.size() <= 3 && stoi(s) <= 255 && (s[0] != '0' || s.size() == 1);

}

 vector<string> restoreIpAddresses(string s) {
      int n = s.size();
        vector<string> ips;
        for (int i = 1; i <= 3 && i < n; i++) {
            for (int j = 1; j <= 3 && i + j < n; j++) {
                for (int k = 1; k <= 3 && i + j + k < n; k++) {
                    string a = s.substr(0, i);
                    string b = s.substr(i, j);
                    string c = s.substr(i + j, k);
                    string d = s.substr(i + j + k);
                    if (valid(d) && valid(c) && valid(b) && valid(a)) {
                        ips.push_back(a + '.' + b + '.' + c + '.' + d);
                    }
                }
            }
        }
        return ips;
    }

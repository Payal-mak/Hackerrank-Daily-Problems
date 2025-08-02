#include <bits/stdc++.h>
using namespace std;

string timeConversion(string s)
{
    string hour = s.substr(0, 2);
    string minutes = s.substr(3, 2);
    string seconds = s.substr(6, 2);
    string period = s.substr(8, 2); // AM or PM

    int hh = stoi(hour);

    if (period == "AM")
    {
        if (hh == 12)
            hh = 0; // 12AM is 00
    }
    else
    { // PM
        if (hh != 12)
            hh += 12;
    }

    // Format the output with leading zeros
    ostringstream oss;
    oss << setw(2) << setfill('0') << hh << ":" << minutes << ":" << seconds;
    return oss.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string s;
    getline(cin, s);

    string result = timeConversion(s);
    fout << result << "\n";

    fout.close();
    return 0;
}

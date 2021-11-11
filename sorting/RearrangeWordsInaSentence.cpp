// intution: we have to sort array in incresing order & return the string in coresponding order.
// take map of length and store the coresponding key as size.

// let map
// key      string
// (size)
// 1
// 2        on
// 3        and
// 4        keep clam code
// 5

class Solution
{
public:
    string arrangeWords(string text)
    {
        // initialize a empty string and map for storing string
        map<int, vector<string>> mp;
        string temp;
        // itirate every character
        for (int i = 0; i < text.size(); i++)
        {
            // if the character is capital then convert to small
            // iterate every element push into temp till not getting space
            if (i < text.size() && text[i] != ' ')
            {
                temp += tolower(text[i]);
            }
            // if we read a word insert it into the map
            if (text[i] == ' ')
            {
                mp[temp.size()].push_back(temp);
                temp = "";
            }
        }
        // for remove the end space in the sentence
        mp[temp.size()].push_back(temp);
        // create a empty string for return result
        string res;
        // iterate map now map in sorted order
        for (auto i : mp)
        {
            // now iterate the map value map store two things one is key another is value
            for (auto c : i.second)
            {
                // now insert word and space
                res += c + " ";
            }
        }
        // now set the first letter of the array to be capital
        res[0] = toupper(res[0]);
        // now remove the space from last index
        res = res.substr(0, res.size() - 1);
        return res;
    }
};
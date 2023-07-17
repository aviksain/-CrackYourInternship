class Solution {
private:
    string kWords(vector<string>& currLine, int currWidth, int maxWidth) {
        int spaces = maxWidth - currWidth;
        int evenSpaces = spaces / (currLine.size() - 1);
        int unEvenSpaces = spaces % (currLine.size() - 1);

        int word = 0;

        // Distribute spaces evenly
        while (word < currLine.size() - 1) {
            int spaces = 0;
            while (spaces < evenSpaces) {
                currLine[word] += ' ';
                spaces++;
            }
            word++;
        }

        // Left must have extra spaces
        word = 0;
        while (unEvenSpaces > 0) {
            currLine[word] += ' ';
            word++;
            unEvenSpaces--;
        }

        string str = "";
        for (int k = 0; k < currLine.size(); k++) {
            if (k == 0) {
                str += currLine[k];
            } else {
                str = str + ' ' + currLine[k];
            }
        }

        return str;
    }

    string oneWord(vector<string>& currLine, int currWidth, int maxWidth) {
        int whiteSpaces = maxWidth - currWidth;
        string str = currLine[0];
        while (whiteSpaces > 0) {
            str += ' ';
            whiteSpaces--;
        }
        return str;
    }

    string lastLine(vector<string>& currLine, int currWidth, int maxWidth) {
        int whiteSpaces = maxWidth - currWidth;
        string str = currLine[0];

        if (currLine.size() > 1) {
            for (int i = 1; i < currLine.size(); i++) {
                str += ' ' + currLine[i];
            }
        }

        while (whiteSpaces > 0) {
            str += ' ';
            whiteSpaces--;
        }

        return str;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> currLine;
        int currWidth = 0;
        for (int i = 0; i < words.size(); i++) {
            int val;
            if(currLine.size() == 0)  
                val = words[i].length();
            else  
                val = (currWidth + words[i].length() + 1);

            if (val <= maxWidth) {
                currLine.push_back(words[i]);
                currWidth = val;
            } 
            else {
                if (currLine.size() > 1) {
                    string str = kWords(currLine, currWidth, maxWidth);
                    ans.push_back(str);
                } else {
                    string str = oneWord(currLine, currWidth, maxWidth);
                    ans.push_back(str);
                }

                currLine.clear();
                currLine.push_back(words[i]);
                currWidth = words[i].length();
            }
        }

        string str = lastLine(currLine, currWidth, maxWidth);
        ans.push_back(str);

        return ans;
    }
};

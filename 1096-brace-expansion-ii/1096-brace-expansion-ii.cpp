class Solution {
public:
    string s;
    int pos;

    // Parse concatenation
    set<string> parseSequence() {
        set<string> result;
        result.insert("");

        while (pos < s.size() &&
               s[pos] != '}' &&
               s[pos] != ',') {

            set<string> current;

            if (s[pos] == '{') {
                pos++; // skip '{'

                current = parseExpression();

                pos++; // skip '}'
            }
            else {
                current.insert(string(1, s[pos]));
                pos++;
            }

            // Concatenate result and current
            set<string> temp;

            for (const string& a : result) {
                for (const string& b : current) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    // Parse union
    set<string> parseExpression() {
        set<string> result;

        while (pos < s.size() && s[pos] != '}') {

            set<string> current = parseSequence();

            // Union
            result.insert(current.begin(), current.end());

            if (pos < s.size() && s[pos] == ',') {
                pos++; // skip ','
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        s = expression;
        pos = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};
/**
 * <h1>PascalStringToken</h1>
 *
 * <p> Pascal string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "../../java/tokens/JavaStringToken.h"

#include <string>

#include "../../java/JavaError.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::java;

JavaStringToken::JavaStringToken(Source *source) throw (string)
    : JavaToken(source)
{
    extract();
}

void JavaStringToken::extract() throw (string)
{
    string value_str = "";

    char current_ch = next_char();  // consume initial quote
    text += "\"";

    // Get string characters.
    do
    {
        // Replace any whitespace character with a blank.
        if (isspace(current_ch)) current_ch = ' ';

        if ((current_ch != '\"') && (current_ch != Source::END_OF_FILE))
        {
            text += current_ch;
            if(current_ch != '\\')
                value_str  += current_ch;
            if(current_ch == '\\')
            {
                current_ch = next_char();
                text += current_ch;
                if(current_ch == 't')
                    value_str += '\t';
                if(current_ch == 'n')
                    value_str += '\n';
                if(current_ch == '"')
                    value_str += '\"';
                current_ch = next_char();
            }
            else
                current_ch = next_char();  // consume character
        }

        
    } while ((current_ch != '\"') && (current_ch != Source::END_OF_FILE));

    if (current_ch == '\"')
    {
        next_char();  // consume final quote
        text += '\"';
        type = (TokenType) PT_STRING;
        value = new DataValue(value_str);
    }
    else
    {
        type = (TokenType) PT_ERROR;
        value = new DataValue((int) UNEXPECTED_EOF);
    }
}

}}}} // namespace wci::frontend::pascal::tokens

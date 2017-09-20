#include "../../java/tokens/JavaCharToken.h"

#include <string>

#include "../../java/JavaError.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::java;

JavaCharToken::JavaCharToken(Source *source) throw (string)
    : JavaToken(source)
{
    extract();
}

void JavaCharToken::extract() throw (string)
{
    string value_str = "";
    
    char current_ch = next_char();  // consume initial quote
    text += "\'";

    // Get characters.
    do
    {
        if ((current_ch != '\'') && (current_ch != EOF) && (current_ch != '\\')) {
            text += current_ch;
            value_str  += current_ch;
            current_ch = next_char();  // consume character
        }
        // Found \?
        if (current_ch == '\\') {
            text  += current_ch;
            current_ch = next_char();
            
            if(current_ch == 't')
                value_str += '\t';
            else if(current_ch == 'n')
                value_str += '\n';
            else
                value_str += current_ch;
            
            text  += current_ch;
            current_ch = next_char();
        }
    } while((current_ch != '\'') && (current_ch != Source::END_OF_FILE));

    if (current_ch == '\'') {
        next_char();  // consume final quote
        text += '\'';
        type = (TokenType) PT_CHARACTER;
        value = new DataValue(value_str);
    }
    else {
        type = (TokenType) PT_ERROR;
        value = new DataValue((int) UNEXPECTED_EOF);
    }
}

}}}} // namespace wci::frontend::pascal::tokens

#ifndef WCI_FRONTEND_JAVA_TOKENS_JAVACHARTOKEN_H_
#define WCI_FRONTEND_JAVA_TOKENS_JAVACHARTOKEN_H_

#include <string>
#include "../JavaToken.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend::java;

class JavaCharToken : public JavaToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    JavaCharToken(Source *source) throw (string);

protected:
    /**
     * Extract a Java string token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::java::tokens

#endif /* WCI_FRONTEND_JAVA_TOKENS_JAVACHARTOKEN_H_ */

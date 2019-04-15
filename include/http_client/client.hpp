#ifndef _NAVAGRAHA_HTTP_CLIENT_CLIENT_H
#define _NAVAGRAHA_HTTP_CLIENT_CLIENT_H

#include <curl/curl.h>
#include <sstream>
#include <string>

namespace navagraha {
namespace http_client {

class client {
private:
    CURL * curl;
    const std::string base_uri;
    std::string result;

    std::string uri(const std::string path) const;

    std::string & curl_abstract_process(const std::string path, CURLoption option);
    std::string & curl_abstract_process(const std::string path, const char * method);

protected:
    std::string & get_call(const std::string path);
    std::string & put_call(const std::string path);
    std::string & delete_call(const std::string path);
    std::string & post_call(const std::string path);
    std::string & patch_call(const std::string path);

public:
    client(CURL * curl, const std::string base_uri);

    size_t write(const char * ptr, size_t size);
};

}
}

#endif

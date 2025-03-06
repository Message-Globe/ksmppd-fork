#include <curl/curl.h>
#include "gwlib/octstr.h"
#include "gwlib/gwlib.h"  // For error() logging
#include "smpp_http_get.h"      // Include the header we just created

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    Octstr *response = (Octstr *) userp;
    octstr_append_data(response, contents, realsize);
    return realsize;
}

Octstr *http_get(const Octstr *url) {
    CURL *curl;
    CURLcode res;
    Octstr *response = octstr_create("");
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, octstr_get_cstr(url));
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            error(0, "curl_easy_perform() failed: %s", curl_easy_strerror(res));
            octstr_destroy(response);
            response = NULL;
        }
        curl_easy_cleanup(curl);
    } else {
        octstr_destroy(response);
        response = NULL;
    }
    return response;
}

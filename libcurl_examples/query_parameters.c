/*******************************************************************************
*
* Program: Send Query Parameters With HTTP Request Using libcurl
*
* Description: Example of using the libcurl library in C to make an HTTP
* request and send query parameters with that request (i.e. get parameters).
*
* YouTube Lesson: https://www.youtube.com/watch?v=NEmOw9gDt9M 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
  // Stores the CURL handle used to manage the request and easy API session    
  CURL *curl;

  // Stores the return value of the call to curl_easy_perform()
  CURLcode result;

  // Starts the session, return the curl handle we'll use to setup the request
  curl = curl_easy_init();

  // If curl_easy_init() fails the function returns an error, we exit with an 
  // error message and status in this case
  if (curl == NULL)
  {
    fprintf(stderr, "HTTP request failed\n");
    return -1;
  }

  // Stores the request URL
  char url[2048];
  
  // Values we wish to put in our request URL for our query parameter values,
  // but the values contain reserved characters, see:
  //
  // https://en.wikipedia.org/wiki/URL_encoding
  //
  // i.e. special characters that have a reserved meaning in URLs.  So we'll
  // need to url encode these strings before we can use them in our URL, 
  // replacing characters like ' ' with %20 (a special code that means ' ').
  //
  char value1[] = "A string with spaces";
  char value2[] = "Special characters %$*"; 
  
  // The function curl_easy_escape() will return a pointer to a URL encoded 
  // version of the string that was pass it as the 2nd argument.  The 1st 
  // argument is the curl handle and the 3rd is the string length (if we 
  // supply 0 as an argument curl_easy_escape() will use the strlen() function
  // in the string.h library to determine the string length).  The URL encoded
  // string is dynamically allocated so we'll need to call curl_free() later 
  // to free the dynamically allocated memory.
  char *v1safe = curl_easy_escape(curl, value1, 0);

  // Output v1safe, notice the ' ' chars in value1 have been replaced with %20
  // v1safe: A%20string%20with%20spaces  (output)
  printf("v1safe: %s\n", v1safe);
  
  // URL encode the value2 string
  char *v2safe = curl_easy_escape(curl, value2, 0);
  
  // Notice the special characters %$* have been replaced
  // v2safe: Special%20characters%20%25%24%2A  (output)
  printf("v2safe: %s\n", v2safe);
  
  // Call sprintf() to build a complete URL string, using the now 'safe' URL 
  // encoded values for our query parameters.  We could apply the same process 
  // to ensure the keys are also URL encoded if there is a concern that they may
  // also contain reserved characters.  sprintf() uses a format string like 
  // printf() except the resulting string will be stored in the url char array.
  sprintf(url, "http://localhost/o.php?key1=%s&key2=%s", v1safe, v2safe);
  
  // curl_easy_setopt() is used to set the options for the request, we MUST set
  // the CURLOPT_URL, i.e. where the request will be to, and we setup a request
  // to the url we have created.
  curl_easy_setopt(curl, CURLOPT_URL, url); 
  
  // curl_easy_perform() will perform the request and return a CURLcode result. 
  // By default the function will output the response to standard output (i.e. 
  // the terminal by default).  In the video demonstration of this code, we used
  // a php script o.php running on localhost that just output the query
  // parameters in the response:
  // 
  // <?php 
  //
  //  print_r($_GET);
  //
  // ?>
  //
  result = curl_easy_perform(curl);

  if (result != CURLE_OK)
  {
    fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
    return -1;
  }
  
  // We call curl_free() to free the dynamically allocated strings v1safe and 
  // v2safe.
  curl_free(v1safe);
  curl_free(v2safe);

  // We call curl_easy_cleanup() to complete the session.
  curl_easy_cleanup(curl); 

  return 0;
}
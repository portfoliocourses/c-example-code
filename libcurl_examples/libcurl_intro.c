/*******************************************************************************
*
* Program: libcurl Library Introduction Example
*
* Description: Example of using the libcurl library in C to make an HTTP 
* request.
*
* YouTube Lesson: https://www.youtube.com/watch?v=mJVchgjkgL8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>

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
  
  // curl_easy_setopt() is used to set the options for the request, we MUST set
  // the CURLOPT_URL, i.e. where the request will be to, and we setup a request
  // to google.com.
  curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");
  
  // curl_easy_perform() will perform the request and return a CURLcode result. 
  // By default the function will output the response to standard output (i.e. 
  // the terminal by default).  We could store the response in a string using
  // the approach below.
  result = curl_easy_perform(curl);
  
  // If the request is OK we'll get back CURLE_OK as a return value, so if we 
  // don't get back CURLE_OK something has gone wrong and we'll exit with an 
  // error message and status.
  if (result != CURLE_OK)
  {
    // The function curl_easy_strerror() will return an error message string 
    // which we output, when it is supplied result as an argument (i.e. the
    // return value from the call to curl_easy_perform()).
    fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
    return -1;
  }
       
  // We call curl_easy_cleanup() to complete the session.
  curl_easy_cleanup(curl);
 
  return 0;
}


// In the below example, we store the response to a string in dynamically 
// allocated memory.  A struct MemoryStruct variable in main called chunk
// will point to the string on the heap.  We use curl_easy_setopt() to have the
// WriteMemoryCallback function called by curl_easy_perform() with each chunk
// of the response string, and this function will concatenate the string to 
// the response string on the heap, using realloc() to expand the allocated 
// memory to the amount of space required.  We choose to output the string 
// before free-ing the space on the heap, but we could have done whatever 
// we wanted with the string, e.g. parse the string.
//

/* 

struct MemoryStruct {
  char *memory;
  size_t size;
};
 
static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, 
                    void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
  
  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if(!ptr) 
  {
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
 
  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
 
  return realsize;
}

int main(void)
{
  CURL *curl;
  CURLcode result;

  struct MemoryStruct chunk; 
  chunk.memory = malloc(1);
  chunk.size = 0;

  curl = curl_easy_init();
  if (curl == NULL)
  {
    fprintf(stderr, "HTTP request failed\n");
    return -1;
  }

  curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");

  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk); 

  result = curl_easy_perform(curl);

  if (result != CURLE_OK)
  {
    fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
    return -1;
  }

  printf("%s <--- response string\n", chunk.memory);

  free(chunk.memory);
  curl_easy_cleanup(curl);
 
  return 0;
}
*/

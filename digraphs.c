%:include <stdio.h>

int main() <%
  char s<::> = "Hello, World";
    printf("%s\n", s);
%>

/* You can use <: and :> instead of [ and ]. Also, <% and %> instead of { and } */

#include <stdio.h>

int main() {

/* [[[cog

import cog, sys
from xml.dom import minidom

xmldoc = minidom.parse('data.xml')
params = xmldoc.getElementsByTagName('Parameter')

for p in params:
	cog.outl("printf(\"" + p.attributes['Text'].value + " = " + p.attributes['Number'].value + "\");")

]]] */
// [[[end]]]

printf("Some non generated text");

}

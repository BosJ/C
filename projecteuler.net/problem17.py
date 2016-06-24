from mechanize import Browser
import lxml.html

br = Browser()
br.open("http://www.calculator.org/calculate-online/mathematics/text-number.aspx")

br.select_form(nr=0)
br.form['ctl00$PlaceHolderMain$TextboxPart1$value'] = '123'

# submit the request
response1 = br.submit()

# print the response, by calling the read() method
html_str = response1.read()

html = lxml.html.fromstring(html_str)

r = html.xpath('//span[@id="ctl00_PlaceHolderMain_g_9554de2f_4c98_4d88_9305_ea23437965b8_ctl00"]/text()')

print r

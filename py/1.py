import os
import sys
import datetime
d=datetime.datetime.strptime("2005-10-8 14:00:00","%Y-%m-%d %H:%M:%S")
d+=datetime.timedelta(days=10)
t=datetime.datetime(1970,1,1,0,0,0)
print(d.strftime("%Y-%m-%d %H:%M:%S"))
d=(d-t)//datetime.timedelta(days=1)
print(d)
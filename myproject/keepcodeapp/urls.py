from django.conf.urls import url
from django.urls import path
from keepcodeapp.views import program_file,add_user,adduser,upload_file

urlpatterns = [
    url(r'add_user',add_user),
    url(r'adduser',adduser),
    url(r'upload_file/$',upload_file),
    url(r'',program_file),
    #url(r'^index/$',dummy),
]

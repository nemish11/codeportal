from django.conf.urls import url
from django.urls import path
from .views import program_file,add_user,adduser,upload_file,upload_input,upload_output

urlpatterns = [
    url(r'add_user',add_user),
    url(r'adduser',adduser),
    url(r'upload_file/$',upload_file),
    url(r'upload_input/$',upload_input),
    url(r'upload_output/$',upload_output),
    url(r'',program_file),
    #url(r'^index/$',dummy),
]

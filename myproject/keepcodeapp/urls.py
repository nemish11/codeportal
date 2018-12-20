from django.conf.urls import url
from django.urls import path
from keepcodeapp.views import save_file,add_user,adduser

urlpatterns = [
    url(r'add_user',add_user),
    url(r'adduser',adduser),
    url(r'',save_file),
    #url(r'^index/$',dummy),
]

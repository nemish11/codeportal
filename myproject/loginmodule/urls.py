from django.conf.urls import url
from django.urls import path
from .views import auth_view,login,logout
from django.contrib.auth import views as auth_views

urlpatterns = [
    url(r'auth',auth_view),
    url(r'login',login),
    url(r'logout',logout),
    url(r'',login)
]

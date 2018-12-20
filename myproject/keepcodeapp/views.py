from django.shortcuts import render
from django.views.generic import TemplateView
from django.http import HttpResponseRedirect
from django.contrib.auth.models import User
from django.contrib.auth.decorators import login_required
import pandas as pd
# Create your views here.
@login_required(login_url="/loginmodule/login")
def save_file(request):
    return render(request,'index.html')

@login_required(login_url="/loginmodule/login")
def add_user(request):
    if not request.user.is_superuser:
        return HttpResponseRedirect('/admin/')
    else:
        username = request.POST.get('username','')
        password1 = request.POST.get('password','')
        user = User.objects.create_user(username=username)
        user.set_password(password1)
        user.save()
        return render(request,'adduser.html')

def adduser(request):
    if request.user.is_superuser:
        return render(request,'adduser.html')
    else:
        return HttpResponseRedirect('/admin/')

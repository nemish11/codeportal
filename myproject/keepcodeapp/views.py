from django.shortcuts import render
from django.views.generic import TemplateView
from django.http import HttpResponseRedirect
from django.contrib.auth.models import User
from django.contrib.auth.decorators import login_required
from django.core.files.storage import FileSystemStorage
import pandas as pd
# Create your views here.
@login_required(login_url="/loginmodule/login")
def program_file(request):
    message = []
    for i in range(1,51):
        message.append(str(i))
    c = {}
    c['message'] = message
    return render(request,'index.html',c)

@login_required(login_url="/loginmodule/login")
def upload_file(request):
    id = request.GET.get('id')
    username = request.session['username']
    file1 = request.FILES["codefile"]
    fs = FileSystemStorage()
    filename = "C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\"+username+"_program"+str(id)+".c"
    if fs.exists(filename):
        fs.delete(filename)
    file2 = fs.save("C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\"+username+"_program"+str(id)+".c", file1)
    message = []
    for i in range(1,51):
        message.append(str(i))
    c = {}
    c['message'] = message
    return render(request,'index.html',c)

@login_required(login_url="/loginmodule/login")
def add_user(request):
    if not request.user.is_superuser:
        return HttpResponseRedirect('/admin/')
    else:
        csv_file = request.FILES["userfile"]
        if not csv_file.name.endswith('.csv'):
            return render(request,'adduser.html')
        if csv_file.multiple_chunks():
            return render(request,'adduser.html')

        data = pd.read_csv(csv_file,names=['username','password'])
        x,y = data.shape
        for i in range(x):
            username = data['username'][i]
            password1 = data['password'][i]
            user = User.objects.create_user(username=username)
            user.set_password(password1)
            user.save()
        return render(request,'adduser.html')

def adduser(request):
    if request.user.is_superuser:
        return render(request,'adduser.html')
    else:
        return HttpResponseRedirect('/admin/')

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
    username = request.session['username']
    fs = FileSystemStorage()
    visited = {}
    inputfile = {}
    outputfile = {}
    message = []
    fname = "C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\UserSubmissions\\"
    fname1 = "C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\InputFiles\\"
    fname2 = "C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\OutputFiles\\"
    for i in range(1,51):
        message.append(str(i))
        filename = fname + username + "_program" + str(i) + ".c"
        if fs.exists(filename):
            visited[str(i)] = str(1)
        filename = fname1 + "input_program" + str(i) + ".txt"
        if fs.exists(filename):
            inputfile[str(i)] = str(1)
        filename = fname2 + "output_program" + str(i) + ".txt"
        if fs.exists(filename):
            outputfile[str(i)] = str(1)
    c = {}
    c['message'] = message
    c['visited'] = visited
    c['inputfile'] = inputfile
    c['outputfile'] = outputfile
    return render(request,'index.html',c)

@login_required(login_url="/loginmodule/login")
def upload_file(request):
    try:
        id = request.GET.get('id')
        username = request.session['username']
        file1 = request.FILES["codefile"]
        fs = FileSystemStorage()
        filename = "C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\UserSubmissions\\"+username+"_program"+str(id)+".c"
        if fs.exists(filename):
            fs.delete(filename)
        file2 = fs.save("C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\UserSubmissions\\"+username+"_program"+str(id)+".c", file1)
        return HttpResponseRedirect('/keepcodeap/program_file/')
    except:
        return HttpResponseRedirect('/keepcodeap/program_file/')

@login_required(login_url="/loginmodule/login")
def upload_input(request):
    try:
        if not request.user.is_superuser:
            return HttpResponseRedirect('/admin/')
        else:
            id = request.GET.get('id')
            file1 = request.FILES["inputfile"]
            fs = FileSystemStorage()
            filename = "C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\InputFiles\\input_program"+str(id)+".txt"
            if fs.exists(filename):
                fs.delete(filename)
            file2 = fs.save("C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\InputFiles\\input_program"+str(id)+".txt", file1)
            return HttpResponseRedirect('/keepcodeap/program_file/')
    except:
        return HttpResponseRedirect('/keepcodeap/program_file/')

@login_required(login_url="/loginmodule/login")
def upload_output(request):
    try:
        if not request.user.is_superuser:
            return HttpResponseRedirect('/admin/')
        else:
            id = request.GET.get('id')
            file1 = request.FILES["outputfile"]
            fs = FileSystemStorage()
            filename = "C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\OutputFiles\\output_program"+str(id)+".txt"
            if fs.exists(filename):
                fs.delete(filename)
            file2 = fs.save("C:\\Users\\Naimish\\Desktop\\Project1\\myproject\\keepcodeapp\\static\\OutputFiles\\output_program"+str(id)+".txt", file1)
            return HttpResponseRedirect('/keepcodeap/program_file/')
    except:
        return HttpResponseRedirect('/keepcodeap/program_file/')

@login_required(login_url="/loginmodule/login")
def add_user(request):
    c = {}
    try:
        if not request.user.is_superuser:
            return HttpResponseRedirect('/admin/')
        else:
            csv_file = request.FILES["userfile"]
            if not csv_file.name.endswith('.csv'):
                c['message'] = "please upload .csv file"
                return render(request,'adduser.html',c)

            if csv_file.multiple_chunks():
                c['message'] = "File is Too large!"
                return render(request,'adduser.html',c)

            data = pd.read_csv(csv_file,names=['username','password'])
            x,y = data.shape
            
            if y != str(2) :
                c['message'] = "File Format is not correct"
                return render(request,'adduser.html',c)

            for i in range(x):
                username = data['username'][i]
                password1 = data['password'][i]
                user = User.objects.create_user(username=username)
                user.set_password(password1)
                user.save()
            c['message'] = "user added Successfully"
            return render(request,'adduser.html',c)
    except:
        c['message'] = "Exception Occured"
        return render(request,'adduser.html',c)

def adduser(request):
    if request.user.is_superuser:
        return render(request,'adduser.html')
    else:
        return HttpResponseRedirect('/admin/')

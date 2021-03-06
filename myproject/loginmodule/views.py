from django.shortcuts import render
from django.views.generic import TemplateView
from django.http import HttpResponseRedirect
from django.contrib import auth
from django.template.context_processors import csrf
from django.contrib import messages

# Create your views here.
def login(request):
	if request.user.is_authenticated:
		if request.user.is_superuser:
			username = request.POST.get('username', '')
			request.session['superuser'] = username
		else:
			request.session['superuser'] = ""
		#messages.add_message(request, messages.INFO, 'You are already Logged in.')
		return HttpResponseRedirect('/keepcodeapp')
	else:
		c = {}
		c.update(csrf(request))
		return render(request, 'login.html', c)

def auth_view(request):
	request.session['superuser'] = ""
	username = request.POST.get('username', '')
	password = request.POST.get('password', '')
	user = auth.authenticate(username=username, password=password)

	if user is not None:
		auth.login(request, user)
		request.session['username']=username
		if request.user.is_superuser:
			request.session['superuser'] = username
		else:
			request.session['superuser'] = ""
		#c={}
		#c['message'] = "Your are now Logged in."
		#messages.add_message(request, messages.INFO, 'Your are now Logged in.')
		return HttpResponseRedirect('/keepcodeapp')
	else:
		messages.add_message(request, messages.WARNING, 'Invalid Login Credentials.')
		return HttpResponseRedirect('/loginmodule/login')

def logout(request):
	if request.user.is_authenticated:
		auth.logout(request)
	request.session['superuser']=""
	request.session['username']= ""
	messages.add_message(request, messages.INFO, 'You are Successfully Logged Out')
	messages.add_message(request, messages.INFO, 'Thanks for visiting.')
	return HttpResponseRedirect('/loginmodule/login/')

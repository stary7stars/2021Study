from django.contrib import admin
from .models import Question, Choice
# Register your models here.

class ChoiceAdmin(admin.ModelAdmin):
    list_filter = ['question']

admin.site.register(Question)
admin.site.register(Choice, ChoiceAdmin)
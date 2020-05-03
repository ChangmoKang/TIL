# Django Migration

Fixtures에 있는 파일을 모델에 맞게 migrate하고 싶다면



아래의 명령어를 실행하고

```
python manage.py makemigrations --empty [appname]
```



migrations 마지막 파일을 `[]` 부분을 수정하여 저장한다.

```python
# -*- coding: utf-8 -*-
from __future__ import unicode_literals

import os, json
from django.db import models, migrations
# from ..models import [app models]


fixture_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), '../fixtures'))
fixture_filename = '[data].json'
fixture_file = os.path.join(fixture_dir, fixture_filename)


def insert_data(apps, schema_editor):
    
    with open(fixture_file) as json_file:
    data = json.load(json_file)
    
    # [관계를 고려하여 작성]


class Migration(migrations.Migration):

    dependencies = [
        ('[app]', '0001_initial'),
    ]

    operations = [
        migrations.RunPython(insert_data),
    ]

```


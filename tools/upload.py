import os
import sys
import glob
import base64

import requests
import humanize


def get_file_list(directory):
	return map(os.path.normpath, glob.glob(directory + '/*'))


def read_file_to_json_string(filename):
	file_ext = os.path.splitext(os.path.basename(filename))[1]
	if file_ext == '.js':
		with open(filename, 'r') as reader:
			return reader.read()
	else:
		with open(filename, 'rb') as reader:
			return {'binary': base64.b64encode(reader.read()).decode('utf-8')}


def upload_files(files, token, branch):
	modules = {}
	for file in files:
		name = os.path.splitext(os.path.basename(file))[0]
		content = read_file_to_json_string(file)
		modules[name] = content
		print('Read {} from {}'.format(humanize.naturalsize(os.path.getsize(file)), file))

	request_body = {
		'branch': branch,
		'modules': modules
	}

	headers = {'X-Token': token}
	r = requests.post('https://screeps.com/api/user/code', headers=headers, json=request_body)
	response = r.json()
	if 'ok' in response:
		print('done')
		return 0
	elif 'error' in response:
		print('failed: ' + response['error'])
		return 1
	else:
		print('unexpected response: ' + r.text)
		return 1


argc = len(sys.argv)
if argc != 3 and argc != 4:
	print('Usage: upload.py <directory> <token> [branch=default]')
	exit(1)

target_directory = sys.argv[1]
token = sys.argv[2]

if argc == 4:
	branch = sys.argv[3]
else:
	branch = 'default'

files = get_file_list(target_directory)
status = upload_files(files, token, branch)
exit(status)

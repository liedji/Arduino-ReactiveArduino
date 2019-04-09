/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _OPERATORTOGGLE_h
#define _OPERATORTOGGLE_h

template <typename T>
class OperatorToggle : public Operator<T, bool>
{
public:
	OperatorToggle(bool state = false);

	void OnNext(T value);

private:
	bool _state = false;
};

template <typename T>
OperatorToggle<T>::OperatorToggle(bool state)
{
	this->_state = false;
}

template <typename T>
void OperatorToggle<T>::OnNext(T value)
{
	this->_state = !this->_state;

	if (this->_childObserver != nullptr) this->_childObserver->OnNext(this->_state);
}
#endif
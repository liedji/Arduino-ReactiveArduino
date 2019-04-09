/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _OPERATORMILLIS_h
#define _OPERATORMILLIS_h

template <typename T>
class OperatorMillis : public Operator<T, unsigned long>
{
public:
	OperatorMillis();

	void OnNext(T value);

	void Reset();

private:
	unsigned long _starTime;
};

template <typename T>
OperatorMillis<T>::OperatorMillis()
{
	_starTime = millis();
}

template <typename T>
void OperatorMillis<T>::Reset()
{
	_starTime = millis();
}

template <typename T>
void OperatorMillis<T>::OnNext(T value)
{
	if (this->_childObserver != nullptr) this->_childObserver->OnNext(millis() - _starTime);
}
#endif
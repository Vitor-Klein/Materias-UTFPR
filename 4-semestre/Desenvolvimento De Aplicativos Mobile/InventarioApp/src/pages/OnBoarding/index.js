
import React from 'react'
import { SafeAreaView, View, Text, Image, TouchableOpacity, TextInput } from 'react-native'
import Onboarding from 'react-native-onboarding-swiper';
import { useNavigation } from '@react-navigation/native'

import styles from './styles'

export default function OnBoarding() {
  const navigation = useNavigation();

  return (
    <View style={styles.container}>
      <Onboarding
        pages={[
          {
            backgroundColor: '#0D3C76',
            image: <Image source={require('../../assets/step1-background.png')} />,
            title: 'Welcome to HomeTidy',
            subtitle: 'Lets keep your home clean and tidy',
          },
          {
            backgroundColor: '#ff6347',
            image: <Image source={require('../../assets/HomeTidyLogo.png')} />,
            title: 'Organize Effortlessly',
            subtitle: 'Track and manage home tasks with ease',
          },
          {
            backgroundColor: '#20b2aa',
            image: <Image source={require('../../assets/HomeTidyLogo.png')} />,
            title: 'Get Started Now',
            subtitle: 'Sign up and make your life easier!',
          },
        ]}
        bottomBarColor='#ffffff00 '
        onSkip={() => navigation.navigate('Login')}
        onDone={() => navigation.navigate('Login')}
      />
    </View>
  )
}

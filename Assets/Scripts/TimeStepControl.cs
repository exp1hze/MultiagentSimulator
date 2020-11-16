using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class TimeStepControl : MonoBehaviour
{
    public GameObject animationControl;
    public GameObject playButton;
    public GameObject nextButton;
    public GameObject prevButton;
    public GameObject tsSlider;

    int previous;
    // Start is called before the first frame update
    void Start()
    {
        previous = 0;
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void setTimeStep()
    {
        if (animationControl.GetComponent<AnimationControl>().toPlay ==false) {

            animationControl.GetComponent<AnimationControl>().curStep = (int)tsSlider.GetComponent<Slider>().value;
            tsSlider.transform.GetChild(2).GetChild(0).GetChild(0).GetComponent<Text>().text = ""+(int)tsSlider.GetComponent<Slider>().value;
            animationControl.GetComponent<AnimationControl>().runOneShot();
        }
    }

    public void toPlay()
    {

        if(animationControl.GetComponent<AnimationControl>().toPlay == true)
        {
            animationControl.GetComponent<AnimationControl>().toPlay = false;
            playButton.transform.GetChild(1).gameObject.SetActive(true);
            playButton.transform.GetChild(0).gameObject.SetActive(false);
        }
        else
        {
            animationControl.GetComponent<AnimationControl>().toPlay = true;
            playButton.transform.GetChild(0).gameObject.SetActive(true);
            playButton.transform.GetChild(1).gameObject.SetActive(false);
        }
        
    }
}

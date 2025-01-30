using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PistolFire : MonoBehaviour
{

    public GameObject pistol;
    public bool isFiring = false;
    public GameObject flash;
    public AudioSource pistolShot;
    public float toTarget;
    public GameObject impactEffect_explosion;//frefab particle hit effects
    public GameObject impactEffect_steam;//frefab particle hit effects
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetButtonDown("Fire1")){// fire1 was the input for the left mouse buton
            if(AmmoDisplay.pistolCount > 0 && isFiring== false)
            //if(isFiring == false)
            {
                StartCoroutine(firePistol());
            }
        }
    }
   //coroutine will be run if the fire1 buttin is pressed and IsFiring is false
   private IEnumerator firePistol()
    {
        isFiring = true;
        Debug.Log("IsFiring True!");

        AmmoDisplay.pistolCount -= 1;

        toTarget = PlayerCasting.distanceFromTarget;

        Debug.Log("Raycast hit object at the position of" + PlayerCasting.point);
        Instantiate(impactEffect_explosion, PlayerCasting.point, Quaternion.LookRotation(Vector3.up, PlayerCasting.normal));
        Instantiate(impactEffect_steam, PlayerCasting.point, Quaternion.LookRotation(Vector3.up, PlayerCasting.normal));

        if (PlayerCasting.killObject.CompareTag("Enemy"))
        {
            Destroy(PlayerCasting.killObject);
        }

        pistol.GetComponent<Animator>().Play("Fire_pistol");
        pistolShot.Play();
        //code for muzzle flash
        flash.SetActive(true);
        yield return new WaitForSeconds(0.05f);
        flash.SetActive(false);
        yield return new WaitForSeconds(0.2f);
        pistol.GetComponent<Animator>().Play("New State");
        isFiring = false;
    }

}

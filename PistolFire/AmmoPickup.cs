using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AmmoPickup : MonoBehaviour
{
    public AudioSource reload;
    public int magcount = 20;

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Ammo"))
        {
            Debug.Log("We're picking up ammo");
            AmmoDisplay.pistolCount += magcount;
            reload.Play();

            Destroy(other.gameObject);
        }
    }
}
